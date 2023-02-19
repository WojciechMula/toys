package main

import (
	"sync"
)

func runAll(funcs ...func()) {
	var wg sync.WaitGroup

	wg.Add(len(funcs))
	for i := range funcs {
		fn := funcs[i]
		go func() {
			fn()
			wg.Done()
		}()
	}

	wg.Wait()
}
