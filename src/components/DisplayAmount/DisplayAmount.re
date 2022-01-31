let signHelper = amount => {
  amount >= 0 ? "+" : "-";
};

[@react.component]
let make = (~amount: int) => {
  <div>
    {React.string(
       String.concat(
         " ",
         [
           signHelper(amount),
           {js|₹|js},
           string_of_int(abs(amount)),
         ],
       ),
     )}
  </div>;
};
