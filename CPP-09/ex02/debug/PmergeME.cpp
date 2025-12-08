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

bool PmergeME::Pair::operator<(const Pair &other)
{
	compCount++;
	if (a < other.a)
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

static intVector getInsertionSeq(intVector& pend) //template
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


static void	binarySearch(int x, int b, intVector& mainChain, int pendSize) //pend[0] has been inserted already // x = 3 2 5 idx = x -1
{//i need pend index; pend position to insert, pend value and mainchain
	int right = std::min(x, (int)mainChain.size() - 1);
    int left  = 0; 

	if (x == pendSize && pendSize % 2 == 1)
		right = mainChain.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
		Pair::compCount++;
        if (mainChain[mid] < b)
            left = mid + 1;
        else
            right = mid;
    }
    mainChain.insert(mainChain.begin() + left, b);
	
}

static void getMainChain_N_Pend(intVector& m, intVector& pend, pairVector& p) /// template
{
	m.push_back(p[0].b);
	m.push_back(p[0].a);
	pend.push_back(p[0].b);
	for (size_t i = 1; i < p.size(); ++i)
	{
		m.push_back(p[i].a);
		pend.push_back(p[i].b);
	}
}
static void insertion(pairVector& left, pairVector& right) //template
{
	for (Pair x : right){
		auto pos = std::lower_bound(left.begin(), left.end(), x);
		left.insert(pos, x);
	}

}
static pairVector merge_insertion(pairVector& c)
{
	if (c.size() <= 1)
		return c;
	
	size_t mid = c.size() / 2;

	pairVector left(c.begin(), c.begin() + mid);
	pairVector right(c.begin() + mid, c.end());

	left = merge_insertion(left);
	right = merge_insertion(right);

	insertion(left, right);
	return left;
	
}

intVector PmergeME::PmergeMe(intVector c)
{
	
	size_t mid = c.size() / 2;
	pairVector pairs;
	
	for (size_t i = 0; i < mid ; ++i)
	{
		int x = i*2; int y = i*2+1;

		if (c[x] < c[y])
			pairs.push_back(Pair(c[y], c[x]));
		else
			pairs.push_back(Pair(c[x], c[y]));;
	}


	pairs = merge_insertion(pairs);

	intVector mainChain;
	intVector pend;
	getMainChain_N_Pend(mainChain, pend, pairs);

	if (c.size() % 2 == 1)
		pend.push_back(c[c.size() - 1]);
    intVector seqInsertion = getInsertionSeq(pend);

	//debug 
	std::cout << "insertion seq: ";
	for (int n : seqInsertion)
    	std::cout << n << " ";
	std::cout << std::endl;

	// debug 
	std::cout << "As: ";
	for (int n : mainChain)
    	std::cout << n << " ";
	std::cout << std::endl;
	std::cout << "Bs: ";
	for (int n : pend)
   		std::cout << n << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	//debug
	int pendSize = pend.size();
    for (size_t i = 0; i < seqInsertion.size(); ++i)
    {
        int x = seqInsertion[i];
        binarySearch(x, pend[x -1], mainChain, pendSize);
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