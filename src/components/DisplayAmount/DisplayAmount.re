let signHelper = amount => {
  amount >= 0 ? React.string("+") : React.string("-");
};

[@react.component]
let make = (~transaction: int) => {
  <div>
    {signHelper(transaction)}
    {React.string({js|₹|js})}
    {React.int(abs(transaction))}
  </div>;
};
