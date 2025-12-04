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

// int main()
// {
//     // Exemplo de vetor "pend"
//     // intVector pend = {5, 3, 8, 1, 4, 2, 7};
// 	intVector pend = {3, 5, 4};

//     // Gerar Jacobsthal
//     intVector jac = genJacobSeq(pend.size());

//     std::cout << "Jacobsthal: ";
//     for (int v : jac)
//         std::cout << v << " ";
//     std::cout << "\n";
// 	std::cout << "Jacobsthal size: " << jac.size();
// 	std::cout << "\n";

//     // Gerar insertion sequence
//     intVector seq = getInsertionSeq(pend);

//     std::cout << "Insertion sequence: ";
//     for (int v : seq)
//         std::cout << v << " ";
//     std::cout << "\n";
// 	std::cout << "Jacobsthal size: " << seq.size();
// 	std::cout << "\n";

//     return 0;
// }

static void stableMove(int oldPos, int newPos, intVector& pend)
{
    int value = pend[oldPos];

    if (newPos > oldPos) {
        for (int i = oldPos; i < newPos; ++i)
            pend[i] = pend[i + 1];
        pend[newPos] = value;
    } else {
        for (int i = oldPos; i > newPos; --i)
            pend[i] = pend[i - 1];
        pend[newPos] = value;
    }
}

static void	binarySearch(int x, int b, intVector& mainChain, intVector& pend) //pend[0] has been inserted already // x = 3 2 5 idx = x -1
{//i need pend index; pend position to insert, pend value and mainchain
	int right = x;
    int left = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (mainChain[mid] < b)
            left = mid + 1;
        else
            right = mid - 1;
    }
    mainChain.insert(mainChain.begin() + left, b);
	stableMove(x, left, pend);

	
}

static void	binarySearch(int x, int b, intVector& mainChain) //pend[0] has been inserted already // x = 3 2 5 idx = x -1
{//i need pend index; pend position to insert, pend value and mainchain
	int right = x;
    int left = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (mainChain[mid] < b)
            left = mid + 1;
        else
            right = mid - 1;
    }
    mainChain.insert(mainChain.begin() + left, b);
	
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

	if (c.size() % 2 == 1)
		lower.push_back(c[c.size() - 1]);
	greater = merge_insertion(greater, lower);

	intVector mainChain;
	intVector &_pend = lower;
	intVector seqInsertion = getInsertionSeq(_pend);

	mainChain.push_back(lower[0]);
	for (int i : greater)
		mainChain.push_back(i);
	
    for (size_t i = 0; i < seqInsertion.size(); ++i)
    {
        int x = seqInsertion[i];
        binarySearch(x, _pend[x -1], mainChain, pend);
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
			lower.push_back(c[i*2]);
			greater.push_back(c[i*2+1]);
		}
		else{
			lower.push_back(c[i*2+1]);
			greater.push_back(c[i*2]);
		}
	}

	if (c.size() % 2 == 1)
		lower.push_back(c[c.size() - 1]);
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