let signHelper = amount => {
  switch (amount) {
  | x when x > 0 => React.string("+")
  | x when x < 0 => React.string("-")
  | _ => React.string("")
  };
};

[@react.component]
let make = (~transaction: int) => {
  <div>
    {signHelper(transaction)}
    {React.string({js|₹|js})}
    {React.int(abs(transaction))}
  </div>;
};
