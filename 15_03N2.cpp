#include<iostream>
#include<ctime>
using namespace std;


void printArr(int arr[], int size);
void generateArr(int arr[], int size);
int deleteElement(int arr[], int size, int);

int main(void) {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int SIZE = 10;
	int arr[SIZE];
	generateArr(arr, SIZE);
	printArr(arr, SIZE);
	int element;
	cout << "Enter number to delete: ";
	cin >> element;
	int result = deleteElement(arr, SIZE, element);
	cout<<"Number of elements: "<<result<<endl;
	printArr(arr, result);
	system("pause");
	return 0;
}

//функция генерации массива
void generateArr(int arr[], int size) {
	int *ptrArr = arr;
	while (ptrArr < (arr + size)) {
		*ptrArr = rand() % 5;
		ptrArr++;
	}
}
//функция вывода массива
void printArr(int arr[], int size) {
	int *ptrArr = arr;
	if (size == 0) cout << "массив пуст";
	while (ptrArr < (arr + size)) {
		printf("%2d\t", *ptrArr);
		ptrArr++;
	}
	cout << endl;
}


int deleteElement(int arr[], int size, int element) {
	int *ptrArr, *ptrTmp;
	ptrArr = arr;
	int counter = size;
	while (ptrArr < (arr + size)) {
		ptrTmp=ptrArr;
		if (*ptrArr == element) {
			counter--;
			size--;
			while (ptrTmp < (arr + size))
			{
				*ptrTmp = *(ptrTmp + 1);
				ptrTmp++;
			}
			continue;
		}
		ptrArr++;
	}
	return counter;
}
