#include "main.hpp"

void    merge_vec(std::vector<int> &vec, std::vector<int> &a, std::vector<int> &b)
{
	vec.erase(vec.begin(), vec.end());
	while (a.size() && b.size()){
		if (a[1] < b[1]){
			vec.push_back(a[0]);
			vec.push_back(a[1]);
			a.erase(a.begin());
			a.erase(a.begin());
		}
		else{
			vec.push_back(b[0]);
			vec.push_back(b[1]);
			b.erase(b.begin());
			b.erase(b.begin());
		}
	}
	while (a.size()){
		vec.push_back(a[0]);
		a.erase(a.begin());
	}
	while (b.size()){
		vec.push_back(b[0]);
		b.erase(b.begin());
	}
}
void    merge_sort_pairs_vec(std::vector<int> &list)
{
	if (list.size() <= 2)
		return ;
	std::vector<int> a;
	std::vector<int> b;
	for(size_t i = 0; i < list.size(); i += 2)
	{
		if (i < list.size() / 2){
			a.push_back(list[i]);
			a.push_back(list[i + 1]);
		}
		else {
			b.push_back(list[i]);
			b.push_back(list[i + 1]);
		}
	}
	merge_sort_pairs_vec(a);
	merge_sort_pairs_vec(b);
	merge_vec(list, a, b);
	return ;
}

void    merge_d(std::deque<int> &deq, std::deque<int> &a, std::deque<int> &b)
{
	deq.erase(deq.begin(), deq.end());
	while (a.size() && b.size()){
		if (a[1] < b[1]){
			deq.push_back(a[0]);
			deq.push_back(a[1]);
			a.erase(a.begin());
			a.erase(a.begin());
		}
		else{
			deq.push_back(b[0]);
			deq.push_back(b[1]);
			b.erase(b.begin());
			b.erase(b.begin());
		}
	}
	while (a.size()){
		deq.push_back(a[0]);
		a.erase(a.begin());
	}
	while (b.size()){
		deq.push_back(b[0]);
		b.erase(b.begin());
	}
}
void    merge_sort_pairs_deq(std::deque<int> &list)
{
	if (list.size() <= 2)
		return ;
	std::deque<int> a;
	std::deque<int> b;
	for(size_t i = 0; i < list.size(); i += 2)
	{
		if (i < list.size() / 2){
			a.push_back(list[i]);
			a.push_back(list[i + 1]);
		}
		else {
			b.push_back(list[i]);
			b.push_back(list[i + 1]);
		}
	}
	merge_sort_pairs_deq(a);
	merge_sort_pairs_deq(b);
	merge_d(list, a, b);
	return ;
}