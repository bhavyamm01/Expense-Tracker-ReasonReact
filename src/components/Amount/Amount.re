[%bs.raw {|require('./Amount.css')|}];

[@react.component]
let make = (~transactions: array(Transaction.t)) => {
  let amountArray = Belt.Array.map(transactions, t => t.amount);

  let calculateTotal = requiredArray => {
    Belt.Array.reduce(requiredArray, 0, (acc, value) => acc + value);
  };

  <div>
    <div className="balance">
      <h3> {React.string("Your balance")} </h3>
      <h1> <DisplayAmount amount={calculateTotal(amountArray)} /> </h1>
    </div>
    <div className="expense-income-div">
      <div className="income-div">
        <h3> {React.string("Income")} </h3>
        <h5 className="income-h5">
          {React.string(
             String.concat(
               " ",
               [
                 {js|₹|js},
                 string_of_int(
                   abs(
                     calculateTotal(Belt.Array.keep(amountArray, i => i > 0)),
                   ),
                 ),
               ],
             ),
           )}
        </h5>
      </div>
      <div className="income-div">
        <h3> {React.string("Expense")} </h3>
        <h5 className="expense-h5">
          {React.string(
             String.concat(
               " ",
               [
                 {js|₹|js},
                 string_of_int(
                   calculateTotal(Belt.Array.keep(amountArray, i => i < 0)),
                 ),
               ],
             ),
           )}
        </h5>
      </div>
    </div>
  </div>;
};
