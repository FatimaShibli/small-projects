import unittest
from app import app, db
from app.models import User, Post

class TestRoutes(unittest.TestCase):

    def setUp(self):
        app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///test.db'
        db.create_all()

    def tearDown(self):
        db.session.remove()
        db.drop_all()

    def test_homepage(self):
        tester = app.test_client(self)
        response = tester.get('/')
        self.assertEqual(response.status_code, 200)

    def test_registration(self):
        tester = app.test_client(self)
        response = tester.post('/register', data=dict(
            username='testuser',
            email='testuser@example.com',
            password='password',
            confirm_password='password'
        ), follow_redirects=True)
        self.assertEqual(response.status_code, 200)
        user = User.query.filter_by(username='testuser').first()
        self.assertIsNotNone(user)
        self.assertEqual(user.email, 'testuser@example.com')

    def test_login(self):
        tester = app.test_client(self)
        tester.post('/register', data=dict(
            username='testuser',
            email='testuser@example.com',
            password='password',
            confirm_password='password'
        ), follow_redirects=True)
        response = tester.post('/login', data=dict(
            email='testuser@example.com',
            password='password'
        ), follow_redirects=True)
        self.assertEqual(response.status_code, 200)

    def test_logout(self):
        tester = app.test_client(self)
        tester.post('/register', data=dict(
            username='testuser',
            email='testuser@example.com',
            password='password',
            confirm_password='password'
        ), follow_redirects=True)
        tester.post('/login', data=dict(
            email='testuser@example.com',
            password='password'
        ), follow_redirects=True)
        response = tester.get('/logout', follow_redirects=True)
        self.assertEqual(response.status_code, 200)

if __name__ == '__main__':
    unittest.main()
