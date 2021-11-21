// gcd
int gcd(int a , int b){
	return b == 0?  gcd(b,a%b);
}

// LCM

int lcm(int a , int b){
	return a*b/ gcd(a,b);   
}