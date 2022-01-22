'use strict';

var React = require("react");
var ReactDom = require("react-dom");
var ExampleStyles$ExpenseTracker = require("./ExampleStyles.bs.js");
var BlinkingGreeting$ExpenseTracker = require("./BlinkingGreeting/BlinkingGreeting.bs.js");
var FetchedDogPictures$ExpenseTracker = require("./FetchedDogPictures/FetchedDogPictures.bs.js");
var ReducerFromReactJSDocs$ExpenseTracker = require("./ReducerFromReactJSDocs/ReducerFromReactJSDocs.bs.js");

var style = document.createElement("style");

document.head.appendChild(style);

style.innerHTML = ExampleStyles$ExpenseTracker.style;

function makeContainer(text) {
  var container = document.createElement("div");
  container.className = "container";
  var title = document.createElement("div");
  title.className = "containerTitle";
  title.innerText = text;
  var content = document.createElement("div");
  content.className = "containerContent";
  container.appendChild(title);
  container.appendChild(content);
  document.body.appendChild(container);
  return content;
}

ReactDom.render(React.createElement(BlinkingGreeting$ExpenseTracker.make, {
          children: "Hello!"
        }), makeContainer("Blinking Greeting"));

ReactDom.render(React.createElement(ReducerFromReactJSDocs$ExpenseTracker.make, {}), makeContainer("Reducer From ReactJS Docs"));

ReactDom.render(React.createElement(FetchedDogPictures$ExpenseTracker.make, {}), makeContainer("Fetched Dog Pictures"));

exports.style = style;
exports.makeContainer = makeContainer;
/* style Not a pure module */
