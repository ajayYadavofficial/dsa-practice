class BrowserHistory {
    private:
        vector<string> _urls;
        int _idx = 0;
        int _lastInsert = 0;

    public:
        BrowserHistory(string homepage) {
            _urls.reserve(100);
            _urls.push_back(homepage);
        }

        void visit(string url) {
            if (_idx == _urls.size() - 1) {
                _urls.push_back(url);
                _lastInsert = ++_idx;
                return;
            }

            _lastInsert = ++_idx;
            _urls[_idx] = url;
        }

        string back(int steps) {
            _idx = std::max(0, _idx - steps);
            return _urls[_idx];
        }

        string forward(int steps) {
            _idx = std::min(_lastInsert, _idx + steps);
            return _urls[_idx];
        }
    };
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */