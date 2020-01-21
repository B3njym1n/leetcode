function node(v) {
    this.value = v;
    this.hgt = 1;
    this.left = null;
    this.right = null;
}

function insert(t, v) {
    if (t == null) {
        t = new node(v);
    } else {
        if (t.value > v) {
            insert(t.left);
        } else {
            insert(t.right);
        }
    }
}

