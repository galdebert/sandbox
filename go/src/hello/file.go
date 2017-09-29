package main

//import "path"
import "path"
import "path/filepath"
import "os"
//import "fmt"
import "os/exec"
import "fmt"
//import "io/ioutil"

func testPath() error {
	exe, err := os.Executable()
	if err != nil {
		return err
	}

	exe = filepath.ToSlash(exe)
	dir := path.Dir(exe)

	cmd := exec.Command("cloc", dir)

	fmt.Println(cmd.Args)

	output, err := cmd.Output()
	if err != nil {
		return err
	}

	fmt.Printf("%s", output)
	return nil
}
