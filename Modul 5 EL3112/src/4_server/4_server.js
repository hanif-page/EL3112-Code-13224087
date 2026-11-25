const express = require('express');
const fs = require('fs');

const app = express();
app.use(express.json());

app.get('/', (req, res) => {
    res.send('Server Active. Use POST to /post to send data!');
});

app.post('/post', (req, res) => {
    const timestamp = new Date().toLocaleString('sv-SE');
    const logEntry = `${JSON.stringify(req.body)}\n`;
    // const logEntry = `[${timestamp}] ${JSON.stringify(req.body)}\n`;

    console.log('JSON Data Accepted:', logEntry.trim());
    fs.writeFileSync('result_data.json', logEntry);

    res.status(200).json({ status: 'success' });
});

app.listen(8000, '0.0.0.0', () => {
    console.log('Server running in Port: 8000. Ctrl+C to Stop.');
});