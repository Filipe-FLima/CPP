#include "PmergeME.hpp"
#include <unordered_set>

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
	if (jacob[0] == jacob[1])
		jacob.erase(jacob.begin());
	return jacob;
}

static intVector getInsertionSeq(intVector& pend)
{
	intVector	seq;
	intVector	jacob;
	std::unordered_set<int>	used;

	jacob = genJacobSeq((int)pend.size());
	for (size_t size = 0; size < pend.size() - 1; ++size)
	{
		int x;
		if (size < jacob.size())
			x = jacob[size];
		else
			x = pend.size();
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
static void	binarySearch(int x, int b, intVector& mainChain) //pend[0] has been inserted already // x = 3 2 5 idx = x -1
{//i need pend index; pend position to insert, pend value and mainchain
	int right = x - 2;
    int left = 0;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mainChain[mid] < b)
            left = mid + 1;
        else
            right = mid;
    }
    mainChain.insert(mainChain.begin() + left, x);
}

static intVector merge_insertion(intVector c, intVector &pend)
{
	if (c.size() <= 1)
		return c;
	size_t mid = c.size() / 2;
	intVector greater, lower;
	for (size_t i = 0; i < mid ; ++i)
	{
		int x = i*2, y = i*2+1;
		if (c[x] < c[y]){
			lower.push_back(c[x]);
			greater.push_back(c[y]);

		}
		else{
			lower.push_back(c[y]);
			greater.push_back(c[x]);
			std::swap(pend[x], pend[y]);
		}
	}

	if (mid % 2 == 1)
		lower.push_back(c[mid - 1]);
	greater = merge_insertion(greater, lower);

	intVector mainChain;
	intVector &_pend = lower;
	intVector seqInsertion = getInsertionSeq(pend);

	mainChain.push_back(lower[0]);
	// _pend.erase(_pend.begin()); //check condition when pend is empty (right before last recursion call)
	for (int i : greater)
		mainChain.push_back(i);
	
    for (size_t i = 0; i < seqInsertion.size(); ++i)
    {
        int x = seqInsertion[i];
        binarySearch(x, _pend[x -1], mainChain);
    }
    return mainChain;
}

intVector PmergeME::sort(intVector c)
{
	if (c.size() <= 1)
		return c;

	size_t mid = c.size() / 2;
	intVector greater, lower;
	for (size_t i = 0; i < mid ; ++i)
	{
		if (c[i*2] < c[i*2+1]){
			lower.push_back(i*2);
			greater.push_back(c[i*2+1]);
		}
		else{
			lower.push_back(c[i*2+1]);
			greater.push_back(c[i*2]);
		}
	}

	if (mid % 2 == 1)
		lower.push_back(c[mid - 1]);
	greater = merge_insertion(greater, lower);

	intVector mainChain;
	intVector &pend = lower;
    intVector seqInsertion = getInsertionSeq(pend);

	mainChain.push_back(lower[0]);
	for (int i : greater)
		mainChain.push_back(i);
	
    for (size_t i = 0; i < seqInsertion.size(); ++i)
    {
        int x = seqInsertion[i];
        binarySearch(x, pend[x -1], mainChain);
    }
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