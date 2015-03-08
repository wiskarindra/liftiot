var express = require('express')
var app = express()
var lantai = 1
var keatas = true
var query

// respond with "Hello World!" on the homepage
app.get('/', function (req, res) {
	res.writeHead(200, {'Content-Type': 'text/plain'});
	res.write(lantai);
	res.end();
})

// accept POST request on the homepage
app.get('/ubah', function (req, res) {
	query = require('url').parse(req.url,true).query;
	lantai = query.lantai;
	keatas = query.keatas;
	res.writeHead(200, {'Content-Type': 'text/plain'});
	// res.write('anda meminta lift untuk menghampiri anda di lantai ');
	res.write(lantai);
	// res.write('kearah atas = ');
	// res.write(keatas);
	res.end();
})

var server = app.listen(3000, function () {

  var host = server.address().address
  var port = server.address().port

  console.log('Example app listening at http://%s:%s', host, port)

})