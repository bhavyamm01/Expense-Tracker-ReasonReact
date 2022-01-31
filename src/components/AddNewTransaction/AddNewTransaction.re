[%bs.raw {|require('./AddNewTransaction.css')|}];

[@react.component]
let make = (~addTransaction: Transaction.t => unit) => {
  let (comment, setComment) = React.useState(_ => "");
  let (amount, setAmount) = React.useState(_ => "0");

  let onSubmit = evt => {
    ReactEvent.Form.preventDefault(evt);
    addTransaction({comment, amount: int_of_string(amount)});
    setComment(_ => "");
    setAmount(_ => "0");
  };

  <div>
    <h3> {React.string("Add new transaction")} </h3>
    <hr />
    <form onSubmit>
      <div className="form-control">
        <label className="form-label">
          <strong> {React.string("Comment")} </strong>
        </label>
        <input
          type_="text"
          placeholder="Add Comment"
          name="comment"
          value=comment
          onChange={event => {
            let value = ReactEvent.Form.target(event)##value;
            setComment(_ => value);
          }}
          required=true
          className="form-input"
        />
      </div>
      <div className="form-control">
        <label className="form-label">
          <strong>
            {React.string("Amount")}
            <br />
            {React.string("(negative - expense, positive - income)")}
          </strong>
        </label>
        <input
          type_="text"
          placeholder="Add Amount"
          name="amount"
          value=amount
          onChange={event =>
            if (ReactEvent.Form.target(event)##value) {
              let value = ReactEvent.Form.target(event)##value;
              setAmount(_ => value);
            }
          }
          className="form-input"
        />
      </div>
      <button type_="submit" className="add-transaction-button">
        {React.string("Add Transaction")}
      </button>
    </form>
  </div>;
};
