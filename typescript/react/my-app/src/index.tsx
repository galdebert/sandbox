import * as React from 'react';
import * as ReactDOM from 'react-dom';
//import App from './App';
import Hello from './components/Hello';
import './index.css';
import registerServiceWorker from './registerServiceWorker';

ReactDOM.render(
  <Hello name="TypeScript" enthusiasmLevel={10} />,
  document.getElementById('root') as HTMLElement // type assertion aka cast
);

// The reason why we need to do "as HTMLElement" is that getElementById's return type is HTMLElement | null
// TypeScript also has a trailing "bang" syntax (!), which removes null and undefined from the prior expression.
// So we could have written document.getElementById('root')!, but in this case we wanted to be a bit more explicit.

registerServiceWorker();
