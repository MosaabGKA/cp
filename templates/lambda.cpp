// inline c++ function
function<void(ll)> remove = [&](ll i) {
    if (lst[i].empty()) return;
    for (auto j: lst[i]) {
        lst[j].erase(i);
        remove(j);
    }
};

auto getY = [&](int from, int to, int y) -> pair<int , int> {
    int left = y - abs(from - to);
    int right = y + abs(from - to);
    left = max(left, 1);
    right = min(right, m);
    return make_pair(left, right);
};
