import * as constants from '../constants'

// Two types that describe what increment actions and decrement actions should look like
export interface IIncrementEnthusiasm {
  type: constants.INCREMENT_ENTHUSIASM;
}

export interface IDecrementEnthusiasm {
  type: constants.DECREMENT_ENTHUSIASM;
}

// EnthusiasmAction describes cases where an action could be an increment or a decrement
export type EnthusiasmAction = IIncrementEnthusiasm | IDecrementEnthusiasm;

// Two functions that actually manufacture the actions which we can use instead of writing out bulky object literals.
export function incrementEnthusiasm(): IIncrementEnthusiasm {
  return {
    type: constants.INCREMENT_ENTHUSIASM
  }
}

export function decrementEnthusiasm(): IDecrementEnthusiasm {
  return {
    type: constants.DECREMENT_ENTHUSIASM
  }
}

// There's clearly boilerplate here,
// so you should feel free to look into libraries like redux-actions once you've got the hang of things.