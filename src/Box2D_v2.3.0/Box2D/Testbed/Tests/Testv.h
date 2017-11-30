  #ifndef FOOTEST_H
  #define FOOTEST_H
    
  class Testv : public Test
    {
        public:
        Testv() 
		{
			b2Body* ground = NULL;
			{
				b2BodyDef bd;
				ground = m_world->CreateBody(&bd);

				b2EdgeShape shape;
				shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
				ground->CreateFixture(&shape, 0.0f);
			}
			b2Body* crawler = NULL;
			{
				b2BodyDef myBodyDef;
  				myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
  				myBodyDef.position.Set(0, 1); //set the starting position
  				myBodyDef.angle = 0; //set the starting angle
				crawler = m_world->CreateBody(&myBodyDef);
				
				b2PolygonShape boxShape;
  				boxShape.SetAsBox(2,1);
  
  				b2FixtureDef boxFixtureDef;
  				boxFixtureDef.shape = &boxShape;
  				boxFixtureDef.density = 5;
				boxFixtureDef.friction = 10;
  				crawler->CreateFixture(&boxFixtureDef);

				// create arm1
				b2Body* arm1 = NULL;
				myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
  				myBodyDef.position.Set(4, 2); //set the starting position
  				myBodyDef.angle = 0; //set the starting angle
				arm1 = m_world->CreateBody(&myBodyDef);
				
  				boxShape.SetAsBox(1.5,0.1);
  
  				boxFixtureDef.shape = &boxShape;
  				boxFixtureDef.density = 1;
  				arm1->CreateFixture(&boxFixtureDef);

                                // create arm2
				b2Body* arm2 = NULL;
				myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
  				myBodyDef.position.Set(7, 2); //set the starting position
  				myBodyDef.angle = 0; //set the starting angle
				arm2 = m_world->CreateBody(&myBodyDef);
				
  				boxShape.SetAsBox(1.5,0.1);
  
  				boxFixtureDef.shape = &boxShape;
  				boxFixtureDef.density = 1;
  				arm2->CreateFixture(&boxFixtureDef);

				// set joint crawler-arm1
				b2RevoluteJointDef revoluteJointDef;
 				revoluteJointDef.bodyA = crawler;
				revoluteJointDef.bodyB = arm1;
				revoluteJointDef.collideConnected = false;
				revoluteJointDef.localAnchorA.Set(2,1);//the top right corner of the box
				revoluteJointDef.localAnchorB.Set(-1.5,0);
  				b2RevoluteJoint* m_joint = (b2RevoluteJoint*)m_world->CreateJoint( &revoluteJointDef );

				revoluteJointDef.bodyA = arm2;
				revoluteJointDef.bodyB = arm1;
				revoluteJointDef.collideConnected = false;
				revoluteJointDef.localAnchorA.Set(-1.5,0);
				revoluteJointDef.localAnchorB.Set(1.5,0);
  				b2RevoluteJoint* n_joint = (b2RevoluteJoint*)m_world->CreateJoint( &revoluteJointDef );
		


			}

   		}
		
        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings); 
    
            //show some text in the main screen
            m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
            m_textLine += 15;

        }
    
        static Test* Create()
        {
            return new Testv;
        }
    };
  
  #endif
