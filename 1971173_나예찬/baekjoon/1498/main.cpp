//#include <iostream>
//#include <string>
//#include <vector>
//
//int main()
//{
//	std::string str;
//	std::cin >> str;
//	int max_n = 2;
//	std::vector<std::pair<int,int>> dataI;
//
//	int strsz = str.size();
//	for (int i = 0; i < strsz / max_n; ++i)
//	{
//		std::string sbstr = str.substr(0, i+1);
//		int vn = 0;
//		std::string comp;
//		do
//		{
//			++vn;
//			comp = str.substr(vn*(i + 1), i + 1);
//		} while (comp == sbstr);
//		if (vn == max_n)
//		{
//			dataI.push_back({ (i + 1)*max_n, max_n });
//		}
//		else if (vn > max_n)
//		{
//			dataI.clear();
//			max_n = vn;
//			dataI.push_back((i+1)*max_n);
//		}
//	}
//	for (int & i : dataI)
//	{
//		std::cout << i << " " << max_n << std::endl;
//	}
//	return 0;
//}