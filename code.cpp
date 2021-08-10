#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int m, n, v, w, x, y;
//=======================

struct Node
{
    int data;
    Node *next;
};

Node *Insert(int x, Node *head)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

void Print(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    Print(head->next);
}

Node *Reverse(Node *head)
{
    Node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node *Multiply(Node *h1, Node *h2)
{
    Node *h3 = new Node;
    Node *pos = h3;
    h3->data = 0;
    h3->next = NULL;
    Node *ptr = h3, *x, *z;
    int carry, val;
    while (h2)
    {
        v = h2->data;
        h2 = h2->next;
        x = h1;
        h3 = pos;
        while (x)
        {
            w = x->data;
            val = v * w + h3->data + carry;
            h3->data = val % 10;
            z = h3;
            if (h3->next == NULL)
            {
                h3->next = new Node;
                h3->next->next = NULL;
                h3->next->data = 0;
            }
            h3 = h3->next;
            carry = val / 10;
            x = x->next;
        }
        pos = pos->next;
        while (carry)
        {
            h3->data = carry % 10;
            carry /= 10;
            z = h3;
            if (h3->next == NULL)
            {
                h3->next = new Node;
                h3 = h3->next;
                h3->next = NULL;
                h3->data = 0;
            }
        }
    }
    z->next = NULL;
    return ptr;
}

int main()
{
    blaze;
    Node *h1 = NULL;
    Node *h2 = NULL;
    Node *h3 = NULL;
    h1 = Insert(3, h1);
    h1 = Insert(2, h1);
    h1 = Insert(1, h1);
    h2 = Insert(9, h2);
    h2 = Insert(9, h2);
    h2 = Insert(9, h2);
    h1 = Reverse(h1);
    h2 = Reverse(h2);
    h3 = Multiply(h1, h2);
    h3 = Reverse(h3);
    cout << "123*999 = ";
    Print(h3);
    return 0;
}