package main

// init known constants
func basicConsts() []*Program {
	return []*Program{
		&Program{value: 0x00000000, name: "VPXORD"},
		&Program{value: 0xffffffff, name: "VPTERNLOG$0xff"},
	}
}
