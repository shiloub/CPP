#include "main.hpp"

void	print_vec(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

std::vector<int> m_i_sort_vec(std::vector<int> vec) {

	int vilain_petit_canard = -1;
	std::vector<int> a;
	std::vector<int> b;

	for (size_t x = 1; x < vec.size(); x += 2) {
		if (vec[x] < vec[x - 1]) {
			int tmp = vec[x];
			vec[x] = vec[x - 1];
			vec[x - 1] = tmp;
		}
	}
	std::vector<int> pairs;
	if (vec.size() % 2)
	{
		vilain_petit_canard = *(vec.end() - 1);
		vec.pop_back();
	}
	merge_sort_pairs_vec(vec);
	pairs = vec;
	for (size_t x = 0; x < pairs.size(); x++) {
	    if (x % 2 == 0)
	        b.push_back(pairs[x]);
	    else
	        a.push_back(pairs[x]);
	}
	if (vilain_petit_canard != -1)
		b.push_back(vilain_petit_canard);
	//insert b in a
	for (size_t x = 0; x < b.size(); x++) {
	    size_t y;
		if (x == 0)
			y = 0;
		else
			y = (x * 2) - 1;
	    for (size_t tmp = 0; tmp <= y; tmp++) {
	        if (b[x] < a[tmp]) {
	            a.insert(a.begin() + tmp, b[x]);
	            break;
	        }
			else if (tmp == y) {
				a.insert(a.begin() + tmp + 1, b[x]);
	            break;
			}

	    }
	}
	return (a);
}

std::deque<int> m_i_sort_deque(std::deque<int> deq) {
	std::deque<int> a;
	std::deque<int> b;
	int vilain_petit_canard = -1;


	for (size_t x = 1; x < deq.size(); x += 2) {
		if (deq[x] < deq[x - 1]) {
			int tmp = deq[x];
			deq[x] = deq[x - 1];
			deq[x - 1] = tmp;
		}
	}
	std::deque<int> pairs;
	if (deq.size() % 2)
	{
		vilain_petit_canard = *(deq.end() - 1);
		deq.pop_back();
	}
	merge_sort_pairs_deq(deq);
	pairs = deq;

	for (size_t x = 0; x < pairs.size(); x++) {
	    if (x % 2 == 0)
	        b.push_back(pairs[x]);
	    else
	        a.push_back(pairs[x]);
	}
	if (vilain_petit_canard != -1)
		b.push_back(vilain_petit_canard);
	//insert b in a
	for (size_t x = 0; x < b.size(); x++) {
	    size_t y;
		if (x == 0)
			y = 0;
		else
			y = (x * 2) - 1;
	    for (size_t tmp = 0; tmp <= y; tmp++) {
	        if (b[x] < a[tmp]) {
	            a.insert(a.begin() + tmp, b[x]);
	            break;
	        }
			else if (tmp == y) {
				a.insert(a.begin() + tmp + 1, b[x]);
	            break;
			}

	    }
	}
	return (a);
}