#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void print(vector<int> input){
    for(const auto& i : input){
        cout << i << " ";
    }
}

// Time: O(n^2) stable Space: O(1);
void Bubble_Sort(vector<int>& input){
    for(int i = input.size() - 1; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            if(input[i] < input[j]){
                int tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
        }
    }
}

// Time: O(n^2) not stable Space: O(1);
void Selection_Sort(vector<int>& input){
    for(int i = 0; i < input.size() - 1; i++){
        int min = INT_MAX;
        int pos = 0;
        for(int j = i + 1; j < input.size(); j++){
            if(min > input[j]){
                min = input[j];
                pos = j;
            }
        }
        if(min > input[i])
            continue;
        int tmp = input[i];
        input[i] = min;
        input[pos] = tmp;
    }
}

// Time: O(n^2) stable Space: O(1);
void Insertion_Sort(vector<int>& input){
    for(int i = 1; i < input.size(); i++){
        int tmp = input[i];
        int j = i - 1;
        while(j >= 0 && input[j] > tmp){
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = tmp;
    }
}

int Partition(vector<int>& input, int low, int high){
    int p = input[high];
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if(input[j] < p){
            i++;
            std::swap(input[j], input[i]);
        }
    }
    std::swap(input[i + 1], input[high]);
    return i + 1;
}

// Time: O(nlogn) not stable Space: O(logn);
void Quick_Sort(vector<int>& input, int low, int high){
    if(low < high) {
        int p = Partition(input, low, high);
        Quick_Sort(input, low, p - 1);
        Quick_Sort(input, p + 1, high);
    }
}

void Merge(vector<int>& input, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> lv(n1, 0);
    vector<int> rv(n2, 0);

    for(int i = 0; i < n1; i++)
        lv[i] = input[l + i];
    for(int i = 0; i < n2; i++)
        rv[i] = input[m + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(lv[i] <= rv[j]){
            input[k] = lv[i];
            k++;
            i++;
        }else{
            input[k] = rv[j];
            k++;
            j++;
        }
    }

    while(i < n1){
        input[k] = lv[i];
        i++;
        k++;
    }

    while(j < n2){
        input[k] = rv[j];
        j++;
        k++;
    }
}

// Time: O(nlogn) stable Space: O(n);
void Merge_Sort(vector<int>& input, int l, int r){
    if(l < r) {
        int m = (l + r) / 2;
        Merge_Sort(input, l, m);
        Merge_Sort(input, m + 1, r);
        Merge(input, l, m, r);
    }
}

void Heapify(vector<int>& input, int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && input[l] > input[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && input[r] > input[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        std::swap(input[i], input[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(input, n, largest);
    }
}

// Time: O(nlogn) not stable Space: O(1);
void Heap_Sort(vector<int>& input, int n){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(input, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>0; i--)
    {
        // Move current root to end
        std::swap(input[0], input[i]);

        // call max heapify on the reduced heap
        Heapify(input, i, 0);
    }

}

int main() {
    vector<int> test = {10, 2, 0, 43, 12, 5};
    //Bubble_Sort(test);
    //Selection_Sort(test);
    //Insertion_Sort(test);
    //Quick_Sort(test, 0, test.size() - 1);
    //Merge_Sort(test, 0, test.size() - 1);
    Heap_Sort(test, test.size());
    print(test);
    return 0;
}