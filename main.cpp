#include<stdio.h>
#include<list>
#include<vector>


int main()
{
	//1970
	std::list<const char*> stations1970{
		"komagome","tabata","nippori","uguisudani","ueno","okachimachi"
		,"akihabara","kanda","tokyo","yurakucho","shimbashi"
		,"hamamatsucho","tamachi","shinagawa","osaki","gotanda"
		,"meguro","ebisu","shibuya","harajuku","yoyogi","shinjuku"
		,"shin-okubo","takadanobaba","mejiro","ikebukuro","otsuka"
		,"sugamo"
	};
	//イテレーター
	std::list<const char*>::iterator itr = stations1970.begin();


	//2019
	std::list<const char*> stations2019 = stations1970;
	//イテレーター
	std::list<const char*>::iterator itr2 = stations2019.begin();
	std::advance(itr2, 2);
	itr2 = stations2019.insert(itr2, "nishinippori");


	//2022
	std::list<const char*> stations2022 = stations2019;
	//イテレーター
	std::list<const char*>::iterator itr3 = stations2022.begin();
	std::advance(itr3, 14);
	itr3 = stations2022.insert(itr3, "takanawa gateway");


	//描画
	//1970
	printf("\n1970\n");
	for (int i = 0; i < stations1970.size(); i++)
	{
		printf("%s,", *itr);
		if (i % 5 == 4)printf("\n");
		itr++;
	}

	//2019
	itr2 = stations2019.begin();
	printf("\n2019\n");
	for (int i = 0; i < stations2019.size(); i++)
	{
		printf("%s,", *itr2);
		if (i % 5 == 4)printf("\n");
		itr2++;
	}

	//2022
	itr3 = stations2022.begin();
	printf("\n2022\n");
	for (int i = 0; i < stations2022.size(); i++)
	{
		printf("%s,", *itr3);
		if (i % 5 == 4)printf("\n");
		itr3++;
	}

	return 0;
}