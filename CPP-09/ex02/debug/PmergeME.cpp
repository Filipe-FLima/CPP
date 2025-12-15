#include "PmergeME.hpp"
#include <unordered_set>

size_t Pair::compCount = 0;

PmergeME::Pair::Pair(int _a, int _b): a{_a}, b{_b}
{
}

PmergeME::Pair::Pair(const Pair& other): a{other.a}, b{other.b}
{
}

PmergeME::Pair& PmergeME::Pair::operator=(const Pair& other)
{
	if (this != &other){
		a = other.a;
		b = other.b;
	}
	return *this;
}

size_t PmergeME::Pair::getComp()
{
    return compCount;
}

bool PmergeME::Pair::operator<(const Pair &other)
{
	compCount++;
	if (a < other.a)
		return true;
	return false;
}

bool PmergeME::Pair::operator==(const int a)
{
	if (this->a == a)
		return true;
    return false;
}

static intVector genJacobSeq(int pendSize)
{
	intVector jacob;

	int current = 1, prev = 0;
	for (int j = current + 2 * prev; j <= pendSize; j = current + 2 * prev)
	{
		if (j > 1)
			jacob.push_back(j);
		prev = current;
		current = j;
	}
	return jacob;
}

intVector PmergeME::getInsertionSeq(size_t pendSize)
{
	intVector	seq;
	intVector	jacob;
	std::unordered_set<int>	used;

	jacob = genJacobSeq((int)pendSize);
	for (size_t size = 0; size < pendSize - 1; ++size)
	{
		int x;
		if (size < jacob.size())
			x = jacob[size];
		else
			x = pendSize;
		while (x > 1)
		{
			if (!used.count(x)){
				seq.push_back(x);
				used.insert(x);
			}
			--x;
		}
	}
	return seq;
}

intVector PmergeME::PmergeMe(intVector& c)
{
	
	size_t mid = c.size() / 2;
	pairVector pairs;
	
	if (c.size() < 2)
		return c;
	for (size_t i = 0; i < mid ; ++i)
	{
		int x = i*2; int y = i*2+1;

		Pair::compCount++;
		if (c[x] < c[y])
			pairs.push_back(Pair(c[y], c[x]));
		else
			pairs.push_back(Pair(c[x], c[y]));;
	}

	intVector As = getAsCont(c, pairs);
	intVector sorted = PmergeMe(As);
	intVector mainChain = insertion(c, sorted, pairs);
    return mainChain;    

}

intDeque PmergeME::PmergeMe(intDeque& c)
{
	
	size_t mid = c.size() / 2;
	pairDeque pairs;

	if (c.size() < 2)
		return c;
	for (size_t i = 0; i < mid ; ++i)
	{
		int x = i*2; int y = i*2+1;

		Pair::compCount++;
		if (c[x] < c[y])
			pairs.push_back(Pair(c[y], c[x]));
		else
			pairs.push_back(Pair(c[x], c[y]));;
	}
	intDeque As = getAsCont(c, pairs);
	intDeque sorted = PmergeMe(As);
	intDeque mainChain = insertion(c, sorted, pairs);
    return mainChain;    

}


static void getNum(std::string token, int& n)
{
    try
    {
        size_t pos;
        n = std::stoi(token, &pos);
        if (pos != token.size())
            throw std::runtime_error("");
    }
    catch (std::exception& e)
    {
        throw std::runtime_error("Error: invalid input in token " + token);
    }
    if (n < 0)
        throw std::runtime_error("Error: negative number in token " + token);
}


void PmergeME::fillContainer(intVector &v, intDeque &d, char **tokens)
{
    int                 n;

    while (*tokens)
    {
        try
        {
            getNum(*tokens, n);
        }
        catch (std::exception& e)
        {
            throw std::runtime_error(e.what());
        }
        if (n < 0)
            throw std::runtime_error("Error: negative number in token " + std::string(*tokens));
        v.push_back(n);
        d.push_back(n);
        ++tokens;
    }
}

intVector PmergeME::getAsIndexs(size_t size)
{
	intVector idxs;

	for (size_t i = 1; i < size + 1; ++i)
		idxs.push_back(i);
	return idxs;
}

void PmergeME::updateIndexAs(int idx, intVector& As)
{
	for (size_t i = 0; i < As.size(); ++i)
	{
		if (As[i] >= idx)
			As[i]++;
	}
}

PmergeME::SortTime::SortTime(): start(std::chrono::steady_clock::now())
{
}

double PmergeME::SortTime::getTime()
{
	auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count();
}
