#include <iostream>
#include <string>
using namespace std;

void mergeArrays(const int array1[], int size1, const int array2[], int size2, int mergedArray[], int& sizeMerged)
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
            mergedArray[k++] = array1[i++];
        else
            mergedArray[k++] = array2[j++];
    }

    while (i < size1)
        mergedArray[k++] = array1[i++];

    while (j < size2)
        mergedArray[k++] = array2[j++];

    sizeMerged = k;
}

void findCommonElements(const int array1[], int size1, const int array2[], int size2) {
    int i = 0, j = 0;

    cout << "Common Elements: ";
    while (i < size1 && j < size2)
    {
        if (array1[i] == array2[j])
        {
            cout << array1[i] << " ";
            i++;
            j++;
        }
        else if (array1[i] < array2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout << endl;
}

bool isPalindrome(const std::string& sentence) {
    int start = 0;
    int end = sentence.length() - 1;

    while (start < end) {
        while (!(('a' <= sentence[start] && sentence[start] <= 'z') || ('A' <= sentence[start] && sentence[start] <= 'Z')) && start < end) {
            start++;
        }

        while (!(('a' <= sentence[end] && sentence[end] <= 'z') || ('A' <= sentence[end] && sentence[end] <= 'Z')) && start < end) {
            end--;
        }

        if (tolower(sentence[start]) != tolower(sentence[end]))
            return false;

        start++;
        end--;
    }

    return true;
}

int main() {
    const int sizeArray1 = 5;
    const int sizeArray2 = 7;

    int array1[sizeArray1];
    int array2[sizeArray2];

    cout << "Enter " << sizeArray1 << " integers for Array1:" << endl;
    for (int i = 0; i < sizeArray1; ++i)
    {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> array1[i];
    }
    cout << endl;
    cout << "Enter " << sizeArray2 << " integers for Array2:" << endl;
    for (int i = 0; i < sizeArray2; ++i)
    {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> array2[i];
    }
    cout << endl;

    const int maxSizeMerged = sizeArray1 + sizeArray2;
    int mergedArray[maxSizeMerged];
    int sizeMerged = 0;

    mergeArrays(array1, sizeArray1, array2, sizeArray2, mergedArray, sizeMerged);

    cout << "Array1: ";
    for (int i = 0; i < sizeArray1; ++i)
    {
        cout << array1[i] << " ";
    }
    cout << endl << "Array2: ";
    for (int i = 0; i < sizeArray2; ++i)
    {
        cout << array2[i] << " ";
    }
    cout << endl;

    cout << "Merged Array: ";
    for (int i = 0; i < sizeMerged; ++i)
    {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    findCommonElements(array1, sizeArray1, array2, sizeArray2);

    string userSentence;
    cin.ignore();
    cout << endl << "Enter a sentence: ";
    getline(cin, userSentence);

    if (isPalindrome(userSentence))
        cout << "The entered sentence is a palindrome." << endl;
    else
        cout << "The entered sentence is not a palindrome." << endl;

    return 0;
}