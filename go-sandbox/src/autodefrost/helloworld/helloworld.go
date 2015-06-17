package main

// Executable commands must always use package main.

import (
	"autodefrost/mypackage"
	"fmt"
	"reflect"
)

func SumAndDiff(a int32, b int32) (int32, int32) {
	return a + b, a - b
}

func SumAndDiff_v2(a int32, b int32) (sum int32, diff int32) {
	sum = a + b
	diff = a - b
	return
}

// Closures, lexically scoped
func MyClosure() func(int) {
	outer := 1
	return func(x int) {
		outer += x
		fmt.Println(outer)
	}
}

func TestClosure() {
	fmt.Println("TestClosure()")
	increment := MyClosure()
	increment(1)
	increment(1)
}

type MyStruct struct {
	a int32
	b float32
}

func NewMyStruct(a int32, b float32) *MyStruct {
	return &MyStruct{a, b}
	// it's perfectly OK to return the address of a local variable
	// the storage associated with the variable survives after the function returns.
	// The expressions new(File) and &File{} are equivalent.
}

func NewMyStruct_2(a int32) *MyStruct {
	return &MyStruct{a: a}
}

// The built-in function make(T, args) serves a purpose different from new(T).
// It creates slices, maps, and channels only, and it returns an initialized (not zeroed) value of type T (not *T)
// The reason for the distinction is that these three types represent, under the covers,
// references to data structures that must be initialized before use
//
// new does nothing but alloc a sizeof(struct) and zero the mem
// make does this *and*
func TestMake() bool {
	// allocates an array of 100 ints and then creates a slice structure with length 10
	// and a capacity of 100 pointing at the first 10 elements
	v1 := make([]int, 10, 100)

	var v2 []int = make([]int, 10, 100)

	return reflect.DeepEqual(v1, v2)
}

func TestArrays() bool {
	// Arrays are values, Assigning one array to another copies all the elements.
	// The size of an array is part of its type
	vec3 := [3]float32{1.0, 1.0, 1.0}
	vec3[0] = 1.0
	vec3[1] = 1.0
	vec3[2] = 1.0

	vec4 := [...]float32{1.0, 1.0, 1.0, 1.0}

	return reflect.DeepEqual(vec3, vec4)
}

func TestSlices() {
	// Slices hold references to an underlying array, and if you assign one slice to another, both refer to the same array
	// If a function takes a slice argument, changes it makes to the elements of the slice will be visible to the caller,
	// analogous to passing a pointer to the underlying array
}

func main() {
	fmt.Println("Hello World!")
	mypackage.MyFunc_1()
	mypackage.MyFunc_2()
	TestClosure()
}
