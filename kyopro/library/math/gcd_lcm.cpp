ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll number1, ll number2) {//lcmを求める
	return number1 / gcd(number1, number2) * number2;
}