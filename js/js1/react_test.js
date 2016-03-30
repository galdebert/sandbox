var React = require('react');
var ReactDOM = require('react-dom');

module.exports.renderJSX = function() {
    ReactDOM.render(
        <h2>renderJSX test ok</h2>,
        document.getElementById('test'));
}