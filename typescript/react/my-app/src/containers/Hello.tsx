import { connect } from 'react-redux';
import { Dispatch } from 'redux';
import * as actions from '../actions/';
import Hello from '../components/Hello';
import { IStoreState } from '../types/index';

// From IStoreState, returns the not-callback props the component need (Hello.IProps)
export function mapStateToProps({ enthusiasmLevel, languageName }: IStoreState) {
  return {
    enthusiasmLevel,
    name: languageName,
  } // return an object that has the fields of Hello.IProps
}

// return the callback props props the component need (Hello.IProps)
export function mapDispatchToProps(dispatch: Dispatch<actions.EnthusiasmAction>) {
  return {
    onDecrement: () => dispatch(actions.decrementEnthusiasm()),
    onIncrement: () => dispatch(actions.incrementEnthusiasm()),
  }
}

// https://stackoverflow.com/questions/39419237/what-is-mapdispatchtoprops
// Note: you can't use mapStateToProps for the same purpose as mapDispatchToProps for the basic reason
// that you don't have access to dispatch inside mapStateToProp. So you couldn't use mapStateToProps
// to give the wrapped component a method that uses dispatch
// I don't know why they chose to break it into two mapping functions - it might have been tidier to
// have mapToProps(state, dispatch, props), ie one function to do both!


// connect will first take mapStateToProps and mapDispatchToProps, and then return another function
// that we can use to wrap our component. Our resulting container is defined with the following line of code:
export default connect(mapStateToProps, mapDispatchToProps)(Hello);
