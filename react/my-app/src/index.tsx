import * as React from 'react';
import * as ReactDOM from 'react-dom';
import registerServiceWorker from './registerServiceWorker';
import './index.css';
import Hello from './components/Hello';
import App from './components/App';

ReactDOM.render(
  <div>
    <App />
    <Hello name="TypeScript" enthusiasmLevel={2} />
  </div>,
  document.getElementById('root') as HTMLElement
);
registerServiceWorker();
