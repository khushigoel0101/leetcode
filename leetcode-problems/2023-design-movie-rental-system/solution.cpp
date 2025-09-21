#include <bits/stdc++.h>
using namespace std;

struct UnRentedComp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        // order by price, then shop
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
};

struct RentedComp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        // order by price, then shop, then movie
        if (a[0] != b[0]) return a[0] < b[0];
        if (a[1] != b[1]) return a[1] < b[1];
        return a[2] < b[2];
    }
};

class MovieRentingSystem {
public:
    set<vector<int>, RentedComp> rented;  // {price, shop, movie}
    unordered_map<int, set<vector<int>, UnRentedComp>> unRented; // movie -> {price, shop}
    unordered_map<int, unordered_map<int, int>> price; // movie -> {shop -> price}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& i : entries) {
            int shop = i[0], movie = i[1], p = i[2];
            unRented[movie].insert({p, shop});
            price[movie][shop] = p;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if (unRented.find(movie) == unRented.end()) return {};
        for (auto& i : unRented[movie]) {
            ans.push_back(i[1]);  // shop
            if (ans.size() == 5) break;
        }
        return ans;
    }

    void rent(int shop, int movie) {
        int p = price[movie][shop];
        unRented[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }

    void drop(int shop, int movie) {
        int p = price[movie][shop];
        rented.erase({p, shop, movie});
        unRented[movie].insert({p, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto& i : rented) {
            ans.push_back({i[1], i[2]}); // shop, movie
            if (ans.size() == 5) break;
        }
        return ans;
    }
};

