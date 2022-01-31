var path = require("path");
var HtmlWebpackPlugin = require("html-webpack-plugin");

module.exports = () => {
  return {
    mode: "development",
    devServer: {
      port: 8000,
      open: true,
      historyApiFallback: true,
      liveReload: true,
    },
    target: "web",
    entry: "./src/Index.bs.js",
    resolve: {
      extensions: [".bs.js", ".js"],
    },
    module: {
      rules: [
        {
          test: /\.css$/i,
          use: ["style-loader", "css-loader"],
        }
      ],
    },
    output: {
      path: path.resolve("./"),
      filename: "bundle.js",
    },
    plugins: [
      new HtmlWebpackPlugin({
        filename: "index.html",
        template: "index.html",
      }),
    ],
  };
};
