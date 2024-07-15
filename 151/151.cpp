int i = s.size() - 1;
        string res;
        // 反向分组循环
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                --i;
            }
            int end = i;
            while (i >= 0 && s[i] != ' ') {
                --i;
            }
            int start = i + 1;
            // 防止s以空格开头
            if (s[start] != ' ') {
                res += s.substr(start, end - start + 1) + ' ';
            }
        }
        // 删去最后一个人为添加的空格
        res.erase(res.size() - 1);
        return res;