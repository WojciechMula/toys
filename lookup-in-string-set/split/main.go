package main

import (
	"bytes"
	"flag"
	"fmt"
	"os"
	"path"
	"strings"
)

func main() {
	var (
		inpath  string
		outpath string
	)
	flag.StringVar(&inpath, "i", "", "input path")
	flag.StringVar(&outpath, "o", "", "output path")
	flag.Parse()
	if inpath == "" || outpath == "" {
		flag.Usage()
		os.Exit(1)
	}

	basename := path.Base(inpath)
	basename, _ = strings.CutSuffix(basename, path.Ext(basename))

	words, err := readList(inpath)
	check(err)

	buf := bytes.NewBuffer(nil)
	generateFunction(buf, basename, words)

	check(os.WriteFile(outpath, buf.Bytes(), 0644))
	fmt.Printf("Created %s\n", outpath)
}

func check(err error) {
	if err != nil {
		fmt.Printf("%s", err)
		os.Exit(2)
	}
}
