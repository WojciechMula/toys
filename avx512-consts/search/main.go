package main

import (
	"bufio"
	"fmt"
	"os"
	"path"
)

func main() {
	//read()
	generate("db")
}

type mutateFunction = func(word uint32, fn func(*Program))

func read() {
	rootdir := "db"

	cp, err := readDirectory(rootdir)
	checkerr(err)

	fmt.Printf("total entries: %d\n", cp.size())

	for val := range cp.vals {
		fmt.Printf("\n")
		fmt.Printf("0x%08x\n", val)
		printprogram(val, cp)
	}
}

func generate(rootdir string) {
	cp := NewConstantPool()

	// find constants
	mfs := []mutateFunction{
		AbsoluteValue,
		LeadingZeroCount,
		ShiftRightLogical,
		ShiftRightArithmetic,
		ShiftLeftLogical,
		RotateRight,
		Negate,
	}

	round := 0

	var better []*Program // we need to keep order of adding item to the main pool

	better = basicConsts()
	for {
		fmt.Printf("Round %d\n", round)
		round += 1

		for val := range cp.vals {
			for _, fun := range mfs {
				fun(val, func(prog *Program) {
					oldprog, ok := cp.vals[prog.value]
					if !ok {
						better = append(better, prog.clone())
						return
					}

					oldcost := cp.programCost(oldprog)
					newcost := cp.programCost(prog)
					if newcost < oldcost {
						fmt.Printf("%08x: %s => %s\n", prog.value, oldprog, prog)
						better = append(better, prog.clone())
					}
				})
			}
		}

		if len(better) == 0 {
			break
		}

		path := fmt.Sprintf("%s/%04d.txt", rootdir, round)
		f, err := os.Create(path)
		checkerr(err)

		for _, prog := range better {
			cp.add(prog)
			f.WriteString(fmt.Sprintf("%s\n", prog))
		}

		err = f.Close()
		checkerr(err)
		fmt.Printf("Created %s\n", path)

		better = better[:0]
	}
}

func readDirectory(rootdir string) (*ConstantPool, error) {
	entries, err := os.ReadDir(rootdir)
	if err != nil {
		return nil, err
	}

	cp := NewConstantPool()
	for _, e := range entries {
		if e.IsDir() {
			continue
		}

		path := path.Join(rootdir, e.Name())
		err = readFile(path, cp)
		if err != nil {
			return nil, err
		}
	}

	return cp, nil
}

func readFile(path string, cp *ConstantPool) error {
	fmt.Printf("Reading %s\n", path)
	f, err := os.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()

	fs := bufio.NewScanner(f)
	fs.Split(bufio.ScanLines)

	for fs.Scan() {
		p, err := deserialize(fs.Text())
		if err != nil {
			return err
		}
		cp.add(p)
	}

	return fs.Err()
}

func checkerr(err error) {
	if err != nil {
		fmt.Printf("%s\n", err)
		os.Exit(2)
	}
}
