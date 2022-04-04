package main

import (
	. "github.com/mmcloughlin/avo/build"
	"github.com/mmcloughlin/avo/buildtags"
	. "github.com/mmcloughlin/avo/operand"
	"github.com/mmcloughlin/avo/reg"
)

type Structure struct {
	bytes []byte
	value uint64
}

func main() {
	Constraint(buildtags.Not("appengine").ToConstraint())
	Constraint(buildtags.Not("noasm").ToConstraint())
	Constraint(buildtags.Term("gc").ToConstraint())
	Constraint(buildtags.Not("noasm").ToConstraint())

	generateSub()
	generateAdd()
	generateStruct()
	Generate()
}

func generateSub() {
	TEXT("Sub", NOSPLIT, "func(x, y uint64) uint64")
	Doc("Sub subtracts x and y.")
	x := reg.R11
	y := reg.R12

	Load(Param("x"), x)
	Load(Param("y"), y)
	SUBQ(x, y)
	Store(y, ReturnIndex(0))
	RET()
}

func generateAdd() {
	TEXT("Add", NOSPLIT, "func(x, y uint64) uint64")
	Doc("Add adds x and y.")
	x := Load(Param("x"), GP64())
	y := Load(Param("y"), GP64())
	ADDQ(x, y)
	Store(y, ReturnIndex(0))
	RET()
}

func generateStruct() {
	Package("main")
	TEXT("CapPlusLen", NOSPLIT, "func(s* Structure)")

	s := Dereference(Param("s"))

	Comment("s.value = len(s.bytes) + cap(s.bytes)")
	length := GP64()
	Load(s.Field("bytes").Len(), length)
	capacity := GP64()
	Load(s.Field("bytes").Cap(), capacity)

	tmp := GP64()
	LEAQ(Mem{Base: length, Index: capacity, Scale: 1}, tmp)

	Store(tmp, s.Field("value"))
}
