// inline c++ function
function<void(ll)> remove = [&](ll i) {
    if (lst[i].empty()) return;
    for (auto j: lst[i]) {
        lst[j].erase(i);
        remove(j);
    }
};
