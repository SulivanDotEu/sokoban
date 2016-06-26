#include <osg/Geode>
#include <osgViewer/Viewer>
#include <iostream>

int main(void)
{
	// Instantiation d'une géométrie 
	osg::ref_ptr<osg::Geometry> carre = new osg::Geometry;

	// Les 4 sommets du carré sont stockés dans un Vec3Array 
	osg::ref_ptr<osg::Vec3Array> vertexArray = new osg::Vec3Array;
	vertexArray->push_back(osg::Vec3(0,1,0));
	vertexArray->push_back(osg::Vec3(1,1,0));
	vertexArray->push_back(osg::Vec3(1,0,0));
	vertexArray->push_back(osg::Vec3(0,0,0));

	// Les couleurs à associer aux sommets sont stockés dans un Vec4Array 
	osg::ref_ptr<osg::Vec4Array> colorArray = new osg::Vec4Array;
	colorArray->push_back(osg::Vec4(1,1,1,1));
	colorArray->push_back(osg::Vec4(1,0,0,1));
	colorArray->push_back(osg::Vec4(0,1,0,1));
	colorArray->push_back(osg::Vec4(0,0,1,1));

	// Le vecteur normal à associer au carré est stocké dans un Vec3Array 
	osg::ref_ptr<osg::Vec3Array> normalArray = new osg::Vec3Array;
	normalArray->push_back(osg::Vec3(0,0,1));

	// Une couleur par sommet 
	carre->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	// Un vecteur normal pour l'ensemble 
	carre->setNormalBinding(osg::Geometry::BIND_OVERALL);
	// Définit le tableau des sommets à utiliser 
	carre->setVertexArray(vertexArray);
	// Définit le tableau des couleurs à utiliser 
	carre->setColorArray(colorArray);
	// Définit le tableau des vecteurs normaux à utiliser 
	carre->setNormalArray(normalArray);

	// Explicite comment il faut utiliser les sommets pour créer la surface requise 
	osg::ref_ptr<osg::DrawElementsUInt> drawElements = new osg::DrawElementsUInt(GL_QUADS);
	drawElements->push_back(3);
	drawElements->push_back(2);
	drawElements->push_back(1);
	drawElements->push_back(0);
	carre->addPrimitiveSet(drawElements);

	// Instancie un noeud de géométrie pour accueillir le carré 
	osg::ref_ptr<osg::Geode> unCarre = new osg::Geode;
	// Désactive le modèle d'éclairage
	osg::StateSet* stateset = unCarre->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
	// Ajoute le carré comme dessin associé au noeud de géométrie 
	unCarre->addDrawable(carre.get());

	// Définir un viewer 
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	// Positionne et dimensionne la fenêtre
	viewer->setUpViewInWindow(32, 32, 512, 512); // en pixels

	// Définit une caméra 
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	// positione la caméra 
	osg::Vec3 eye = osg::Vec3(0,0,1);
	osg::Vec3 center = osg::Vec3(0,0,0);
	osg::Vec3 up = osg::Vec3(0,1,0);
	camera->setViewMatrixAsLookAt(eye,center,up);
	// Définit un volume de projection 
	camera->setProjectionMatrixAsOrtho(-0.5,1.5,-0.5,1.5,0.5,5);
	// Définit une viewport où projeter le modèle 
	camera->setViewport(new osg::Viewport(10,10,400,400));
	// Annule la caméra par défaut 
	camera->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
	// Définit la couleur de fond de la viewport de la caméra 
	camera->setClearColor(osg::Vec4(0.5,0.5,0.5,1));

/*	// Récupère le positionnement de la caméra par défaut et l'affiche à la console
	viewer->getCamera()->getViewMatrixAsLookAt(eye,center,up);
	std::cout << "eye x : " << eye[0] << std::endl;
	std::cout << "eye y : " << eye[1] << std::endl;
	std::cout << "eye z : " << eye[2] << std::endl;
	std::cout << "center x : " << eye[0] << std::endl;
	std::cout << "center y : " << eye[1] << std::endl;
	std::cout << "center z : " << eye[2] << std::endl;
	std::cout << "up x : " << eye[0] << std::endl;
	std::cout << "up y : " << eye[1] << std::endl;
	std::cout << "up z : " << eye[2] << std::endl;*/

	// Définit la couleur de fond de la viewport de la caméra par défaut
	viewer->getCamera()->setClearColor(osg::Vec4(0,0.7,0.7,1));

	// Associe le noeud contenant le carré à la caméra 
	camera->addChild(unCarre);

	// Démarre le graphe de scène au noeud correspondant à la caméra 
	viewer->setSceneData(camera.get());

	// Lance la boucle de rendu associée au viewer défini 
	return viewer->run();
}