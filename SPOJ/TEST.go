package main
import "fmt"
// how to pass by reference ?
func main() {
	var n int
	for {
		fmt.Scan(&n)
		if n != 42 {
			fmt.Println(n)
		} else {
			break
		}
	}
}
