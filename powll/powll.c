unsigned long long powll(unsigned long long a, unsigned long long b)
{
	unsigned long long ret = 1;
	for (unsigned long long i = 0; i < b;i++)
		ret *= a;
	return ret;
}
