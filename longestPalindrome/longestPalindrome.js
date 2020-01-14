var longestPalindrome = function (s) {
    let l, r;
    let find = false;
    let sub;
    let size = s.length;
    while (size > 1) {
	for (l = 0; l + size <= s.length; l++) {
	    r = l + size - 1;
	    let lc = l, rc = r;
	    // validate
	    while (lc < rc) {
		if (s[lc] == s[rc]) {
		    if (rc - lc <= 2) {
			find = true;
		    }
		    lc++;
		    rc--;
		} else {
		    break;
		}
	    }
	    if (find) {
		sub = s.substring(l,l+size);
		break;
	    }
	}
	if (find) {
	    break;
	}
	size--;
    }
    if (s.length == 1) sub = s;
    if (sub == '') sub= s.substring(0,1);
    return sub;
};

console.log(longestPalindrome("babad"));
