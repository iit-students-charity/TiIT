#pragma once
#ifndef set_H
#define set_H
#include <vector>
using namespace std;

template <typename T>
class Set 
{
	private:
		vector <T> vct;
		int posit;
		T elem;

	public:
		void set(T buffer) //addditing to the end
		{
			vct.push_back(buffer);
		} 
		T get(int cnt)
		{
			return vct[cnt];
		}
		int get_da_power()
		{
			return vct.size();
		}
		void del(T elem)
		{
			for (unsigned int i = 0; i < vct.size(); i++)
			{
				if (vct[i] == elem)
				{
					vct.erase(vct.begin() + i);
				}
			}
		}
		bool is_there(T elem)
		{
			for (unsigned int i = 0; i < vct.size(); i++)
			{
				if (vct[i] == elem)
				{
					return true;
					break;
				}
			}
			return false;
		}
		void uni(Set<T> v1, Set<T> v2)
		{
			Set <T> un;

			for (unsigned int i = 0; i < v1.vct.size(); i++)
			{
				un.vct.push_back(v1.vct[i]);
			}
			unsigned int sz = un.vct.size();
			bool state = false;
			for (unsigned int j = 0; j < v2.vct.size(); j++)
			{
				for (unsigned int k = 0; k < sz; k++)
				{
					if (v2.vct[j] == un.vct[k])
					{
						state = true;
					}
				}
				if (!state)
				{
					un.vct.push_back(v2.vct[j]);
				}
				state = false;
			}

			*this = un;
		}
		void inter(Set<T> v1, Set<T> v2)
		{
			Set <T> inter;

			bool state = false;
			for (unsigned int i = 0; i < v1.vct.size(); i++)
			{
				for (unsigned int j = 0; j < v2.vct.size(); j++)
				{
					if (v1.vct[i] == v2.vct[j])
					{
						state = true;
					}
					if (state)
					{
						inter.vct.push_back(v2.vct[j]);
					}
					state = false;
				}
			}

			*this = inter;
		}

};
#endif