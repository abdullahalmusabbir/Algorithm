#include<bits/stdc++.h>
using namespace std;

struct job {
    string id;
    int deadline;
    int profit;
};

bool comp(job j1, job j2) {
    return (j1.profit > j2.profit);
}

int main() {
    int n;
    printf("\nEnter Size: ");
    scanf("%d", &n);
    job jobs[n];
    printf("\nEnter job's id, deadline, and profit: ");
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs, jobs + n, comp);

    int jobseq[n];
    bool G_chart[n];
    for(int i = 0; i < n; i++) {
        G_chart[i] = false;
    }

    for(int i = 0; i < n; i++) {
        for(int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if(G_chart[j] == false) {
                jobseq[j] = i;
                G_chart[j] = true;
                break;
            }
        }
    }

    cout << "\nJob Sequence: ";
    for(int i = 0; i < n; i++) {
        if(G_chart[i]) {
            cout << jobs[jobseq[i]].id << " ";
        }
    }
}
