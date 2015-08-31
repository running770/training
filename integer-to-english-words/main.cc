#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	string numberToWords100(int num) {
	
		string s;
	
		string less20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		
		string tenstr[] = {"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	
		if (num < 20) {
			s = less20[num%100];
		}
		else {
			int units = num%10;
			int tens = num%100/10;
			int hundreds = num/100;
			
			if (num%100 < 20){
				tens = 0;
				units = num%100;
			}
			
			
			s = hundreds?less20[hundreds] + " Hundred":"";
			s += tens?(s.length()?" ":"") + tenstr[tens]:"";
			s += units?(s.length()?" ":"") + less20[units]:"";	
		}
		
		return s;
	}

	string numberToWords(int num) {

		if (0 == num){
			return "Zero";
		}

		string bigs[] = {"Thousand", "Million", "Billion"};

		string s = numberToWords100(num%1000);
	
		for (int i=0;i<3;++i){
			num /= 1000;
			s = (num%1000)?(numberToWords100(num%1000) + " " + bigs[i] + (s.length()?" " + s:"")):(s);
		}
		
		return s;
		
	}

};


int main(int argc, char** argv)
{
	int number = 0;
	
	Solution solution;
	
	while (cin >> number) {
	
		string s = solution.numberToWords(number);
	
		cout << s << endl;
	}
	
	
	return 0;
}