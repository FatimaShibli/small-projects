from flask import Flask, render_template, request, redirect, url_for, session, send_file
from models import User, db
from utils import hash_password, verify_password
import pandas as pd

app = Flask(__name__)
app.config.from_pyfile('config.py')

db.init_app(app)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        email = request.form['email']
        password = request.form['password']
        user = User.query.filter_by(email=email).first()
        if user and verify_password(password, user.password):
            session['user_id'] = user.id
            return redirect(url_for('dashboard'))
        else:
            error = 'Invalid email or password'
            return render_template('login.html', error=error)
    else:
        return render_template('login.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        email = request.form['email']
        password = request.form['password']
        confirm_password = request.form['confirm_password']
        user = User.query.filter_by(email=email).first()
        if user:
            error = 'Email already exists'
            return render_template('register.html', error=error)
        elif password != confirm_password:
            error = 'Passwords do not match'
            return render_template('register.html', error=error)
        else:
            hashed_password = hash_password(password)
            new_user = User(email=email, password=hashed_password)
            db.session.add(new_user)
            db.session.commit()
            session['user_id'] = new_user.id
            return redirect(url_for('dashboard'))
    else:
        return render_template('register.html')

@app.route('/dashboard')
def dashboard():
    if 'user_id' in session:
        user = User.query.get(session['user_id'])
        return render_template('dashboard.html', user=user)
    else:
        return redirect(url_for('login'))

@app.route('/logout')
def logout():
    session.pop('user_id', None)
    return redirect(url_for('login'))

@app.route('/import', methods=['POST'])
def import_data():
    if request.method == 'POST':
        file = request.files['file']
        df = pd.read_excel(file)
        # process data
        return redirect(url_for('dashboard'))

@app.route('/export', methods=['GET'])
def export_data():
    if 'user_id' in session:
        user = User.query.get(session['user_id'])
        data = pd.read_sql(f"SELECT * FROM users WHERE email = '{user.email}'", db.engine)
        file = data.to_excel(index=False)
        return send_file(file, as_attachment=True, attachment_filename='exported_data.xlsx')
    else:
        return redirect(url_for('login'))
