package main

import (
	"fmt"
)

type myInterface interface {
	doStuff() int
	doOtherStuff() float32
}

type myStructA struct {
}

func (a *myStructA) doStuff() {
	fmt.Println("MyStructA.doStuff()", a)
}

func (a *myStructA) doOtherStuff() {
	fmt.Println("MyStructA.doOtherStuff()", a)
}

type myStructB struct {
}

func (b *myStructB) doStuff() {
	fmt.Println("MyStructB.doStuff()", b)
}

func (b *myStructB) doOtherStuff() {
	fmt.Println("MyStructB.doOtherStuff()", b)
}
