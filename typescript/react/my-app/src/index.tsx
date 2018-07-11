import * as React from 'react';
import * as ReactDOM from 'react-dom';
import { Provider } from 'react-redux';
import { createStore } from 'redux';
import Hello from './containers/Hello'; // import Hello from './components/Hello';
import './index.css';
import { enthusiasm } from './reducers/index';
import registerServiceWorker from './registerServiceWorker';

const store = createStore(enthusiasm, {
  enthusiasmLevel: 1,
  languageName: 'TypeScript',
});

ReactDOM.render(
  <Provider store={store}>
    <Hello />
  </Provider>,
  document.getElementById('root') as HTMLElement
);;

// ReactDOM.render(
//   <Hello name="TypeScript" enthusiasmLevel={10} />,
//   document.getElementById('root') as HTMLElement // type assertion aka cast
// );

// The reason why we need to do "as HTMLElement" is that getElementById's return type is HTMLElement | null
// TypeScript also has a trailing "bang" syntax (!), which removes null and undefined from the prior expression.
// So we could have written document.getElementById('root')!, but in this case we wanted to be a bit more explicit.

registerServiceWorker();
