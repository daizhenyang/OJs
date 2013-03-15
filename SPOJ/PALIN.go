package main
import "fmt"

//rune is unicode
func reverse(s string) string {
	runes := []byte(s)
    	for i, j := 0, len(runes) - 1; i < j; i, j = i + 1, j - 1 {
        	runes[i], runes[j] = runes[j], runes[i]
    	}
    	return string(runes)
}
func addOne(knum string) string {
	n := len(knum)
	v := 1
	runes := []byte(knum)
	for i:= n - 1;i >= 0 && v == 1;i-- {
		if knum[i] == '9' {
			runes[i] = '0'
		} else {
			//unicode can't assigned by uint8
			runes[i] = knum[i] + 1
			v = 0
		}
	}
	if v == 1 {
		return "1" + string(runes[0 : ])
	}
	return string(runes[0 : ])
}
func getPalindrome(knum string) (ret string) {
	n    := len(knum)
	half := knum[0 : (n + 1) / 2]
	ret   = half + reverse(knum[0 : n / 2])
	if ret > knum {
		return ret
	}
	half  = addOne(half)
	return half + reverse(half[0 : n / 2])
}
func main() {
	var tcase int
	var knum  string
	fmt.Scan(&tcase)
	for i := 0;i < tcase;i++ {
		fmt.Scan(&knum)
		fmt.Println(getPalindrome(knum))
	}
}

