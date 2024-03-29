#include "Shadows.h"

Shadows::Shadows() {}
Shadows::Shadows(GLuint depthShader) {
	this->depthShader = depthShader;
}

void Shadows::generateIDs(GLuint shaderID) {
	depthMatrixID = glGetUniformLocation(depthShader, "depthMVP");
	depthBiasID = glGetUniformLocation(shaderID, "DepthBiasMVP");
	shadowMapID = glGetUniformLocation(shaderID, "shadowMap");
}

glm::mat4 Shadows::sendToShaderForShadowCalculations(glm::mat4 *model, Light *light) {
	glm::mat4 depthProjectionMatrix = glm::ortho<float>(-10, 10, -10, 10, -10, 20);
	//to avoid nand in the depthViewMatrix
	if (light->pos.x == 0) {
		light->pos.x = 0.01;
	}
	glm::mat4 depthViewMatrix = glm::lookAt(light->pos, glm::vec3(0,0,0), glm::vec3(0, 1, 0));
	glm::mat4 depthMVP = depthProjectionMatrix * depthViewMatrix * *model;
	glUniformMatrix4fv(depthMatrixID, 1, GL_FALSE, glm::value_ptr(depthMVP));
	glm::mat4 biasMatrix = glm::mat4(
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
		);

	glm::mat4 depthBiasMVP = biasMatrix*depthMVP;
	return depthBiasMVP;
}

void Shadows::sendToShaderForObjectCalculations(glm::mat4 *depthBiasMVP) {
	glUniformMatrix4fv(depthBiasID, 1, GL_FALSE, glm::value_ptr(*depthBiasMVP));
}

void Shadows::activateDepthTexture(GLuint depthTexture) {
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glUniform1i(shadowMapID, 1);
}
