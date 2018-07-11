# TypeScript React Starter

https://github.com/Microsoft/TypeScript-React-Starter

```
npm install -g create-react-app
create-react-app my-app --scripts-version=react-scripts-ts
cd my-app
npm run start   # or npm start - spawns off a server which reloads the page as we save our files
npm run test    # or npm test  - uses Jest, it automatically runs as soon as it detects changes
npm run build   # creates an optimized JS and CSS build in ./build/static/js and ./build/static/css respectively.
```

If you'd like, you can run `npm run start` and `npm run test` side by side so that you can preview changes and test them simultaneously.



# Writing tests with Jest

Because we use React 16, run
```
npm install -D enzyme @types/enzyme enzyme-adapter-react-16 @types/enzyme-adapter-react-16
```

DO NOT RUN:
```
npm install -D enzyme @types/enzyme react-addons-test-utils
```
that does not work with react 16

From https://github.com/facebook/react/issues/11214. The test utils for React 16 are included in React DOM. You can import them like so
```
import ReactTestUtils from 'react-dom/test-utils'
```

We also had to install react-addons-test-utils. This is something enzyme expects to be installed.

Enzyme is a common tool in the React ecosystem that makes it easier to write tests for how components will behave. By default, our application includes a library called jsdom to allow us to simulate the DOM and test its runtime behavior without a browser. Enzyme is similar, but builds on jsdom and makes it easier to make certain queries about our components.


```
import * as Enzyme from 'enzyme';
import * as Adapter from 'enzyme-adapter-react-16';
import * as React from 'react';
import Hello from './Hello';
```

https://github.com/facebook/react/issues/11214


# Adding state management

As far as a React component is concerned, data flows down through its children through the props you specify on each element.

**Redux** relies on synchronizing data through a centralized and immutable store of data, and updates to that data will trigger a re-render of our application. State is updated in an immutable fashion by sending explicit action messages which must be handled by functions called reducers. Because of the explicit nature, it is often easier to reason about how an action will affect the state of your program.

**MobX** relies on functional reactive patterns where state is wrapped through observables and passed through as props. Keeping state fully synchronized for any observers is done by simply marking state as observable. As a nice bonus, the library is already written in TypeScript.

```
npm install redux react-redux @types/react-redux
```

actually I think this is better:
```
npm install redux react-redux
npm install -D @types/react-redux
```

There is no `@types/redux` because Redux provides its own type definitions, so you don't need anything more!



# containers

When writing with Redux, we will often write **components** as well as **container**. Components are often data-agnostic, and work mostly at a presentational level. **Containers typically wrap components and feed them any data that is necessary to display and modify state**.


