var unique = require('uniq');

module.exports.testFunc = function() {
    var data = [1, 2, 2, 3, 4, 5, 5, 5, 6];
    document.getElementById('test').innerHTML = unique(data);
}