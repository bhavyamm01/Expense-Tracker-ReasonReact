open Transactions;

[@react.component]
let make = (~addTransaction: state => unit) => {
  let (comment, setComment) = React.useState(_ => "");
  let (amount, setAmount) = React.useState(_ => "0");

  let labelStyle =
    ReactDOM.Style.make(
      ~display="block",
      ~margin="2% 0",
      ~fontSize="15px",
      (),
    );

  let inputStyle =
    ReactDOM.Style.make(
      ~display="block",
      ~width="100%",
      ~padding="2%",
      ~borderRadius="2%",
      ~fontSize="14px",
      ~border="1px solid #dedede",
      (),
    );

  let addTransactionStyle =
    ReactDOM.Style.make(
      ~display="block",
      ~width="100%",
      ~marginTop="4%",
      ~padding="2%",
      ~border="none",
      ~backgroundColor="blueviolet",
      ~color="white",
      ~borderRadius="2%",
      ~cursor="pointer",
      ~fontSize="16px",
      (),
    );

  let onSubmit = evt => {
    ReactEvent.Form.preventDefault(evt);
    addTransaction({comment, amount: int_of_string(amount)});
    setComment(_ => "");
    setAmount(_ => "0");
  };

  <div className="add_new_transaction">
    <h3> {React.string("Add new transaction")} </h3>
    <hr />
    <form onSubmit>
      <div className="form-control">
        <label style=labelStyle>
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
          style=inputStyle
        />
      </div>
      <div className="form-control">
        <label style=labelStyle>
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
          style=inputStyle
        />
      </div>
      <button type_="submit" style=addTransactionStyle>
        {React.string("Add Transaction")}
      </button>
    </form>
  </div>;
};
